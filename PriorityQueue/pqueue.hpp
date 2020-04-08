/*
 * Filename:      pqueue.hpp
 * Version:       1.0
 * Author:        zah
 * Last Modified: Thu Dec 01, 2016 (06:40 PM)
 *
 * Copyright © 2016 zah
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef PQUEUE

#define PQUEUE 

#include "dynarray.hpp"
#include <cstddef>
using std::size_t;
#include <new>
using std::bad_alloc;
#include <iostream>
using std::cout;


namespace zh{


    //============================================||
    //					          ||
    // 		       Prototype 	          ||
    //					          ||
    //============================================||

    template <typename T>
        class Less {
            public:
                bool operator()(const T& a, const T&b) const{
                    if (a < b){
                        return true;
                    }else {
                        return false;
                    }
                }
        };

    template <typename T, typename F = Less<T> >
        class PQueue{
            public:
                typedef size_t        size_type;
                typedef T*            pointer;
                typedef T&            reference;
                typedef const T*      const_pointer;
                typedef const T&      const_reference;
                typedef T             value_type;

                PQueue();
                explicit PQueue(F);
                size_type size() const;
                bool empty() const;
                void clear();
                void enQueue(const T&);
                void deQueue();
                const T& getTop() const;
                void buildHeap();
                void shiftdown(size_type hole);
                void print() const;

                template <typename SQITER>
                    PQueue(SQITER begin, SQITER end);

            private:
                DArray<T> bheap;
                F callback;
        };


    //--------------------------------------------||
    //						  ||
    // 	                Class PQueue              ||
    //					          ||
    //--------------------------------------------||

    template <typename T, typename F>
        PQueue<T,F>::PQueue(): 
            bheap(), callback(){}


    template <typename T, typename F>
        PQueue<T,F>::PQueue(F fptr): 
            bheap(), callback(fptr){}


    template <typename T, typename F>
        void PQueue<T,F>::enQueue(const T& item){
            /* We assume that if empty(), logicalSize = 0 */
            bheap.append(item);

            int hole = bheap.size() - 1;
            int parent = (hole-1)/2;

            while (hole > 0 && callback(item, bheap[parent])){
                bheap[hole] = bheap[parent];
                hole = parent;
                parent = (hole-1)/2;
            }

            bheap[hole] = item;
        }


    template <typename T, typename F>
        void PQueue<T,F>::deQueue(){
            if (empty()){
                return;
            } else{
                bheap[0] = bheap[(bheap.size()-1)];
                shiftdown(0);
                bheap.remove_last();
            }
        }


    template <typename T, typename F>
        void PQueue<T,F>::shiftdown(size_type hole){
            T tmp = bheap[hole];
            size_type child = hole * 2 + 1;
            size_type lastNode = bheap.size() - 1;

            while ( child <= lastNode){
                if (child < lastNode && 
                        callback(bheap[child+1], bheap[child])){
                    ++child;
                }

                if (callback(bheap[child], tmp)){
                    bheap[hole] = bheap[child];
                    hole = child;
                    child = hole * 2 + 1;
                } else {
                    break;
                }
            }

            bheap[hole] = tmp;
        }



    template <typename T, typename F>
        bool PQueue<T,F>::empty() const{
            if (bheap.empty()){
                return true;
            }else {
                return false;
            }
        }

    template <typename T, typename F>
        typename PQueue<T,F>::size_type PQueue<T,F>::size() const{
            return bheap.size();
        }

    template <typename T, typename F>
        const T& PQueue<T,F>::getTop() const {
            return bheap[0];
        }


    template <typename T, typename F>
        void PQueue<T,F>::clear(){
            if (!empty()){
                bheap.clear();
            }
        }


    template <typename T, typename F>
        void PQueue<T,F>::buildHeap(){
            if (bheap.size() < 2){
                return;
            }

            for (int i = (bheap.size())/2 - 1; i >= 0; --i){
                shiftdown(i);
            }
        }

    template <typename T, typename F>
        template <typename SQITER>
        PQueue<T,F>::PQueue(SQITER begin, SQITER end){
            for (SQITER itr = begin; itr != end; ++itr){
                enQueue(*itr);
            }
        }

    template <typename T, typename F>
        void PQueue<T,F>::print() const{
            if (!this->empty()){
                for (auto i : bheap){
                    cout << i << " ";
                }

            }

        }

} /* namespace zh */

#endif /* ifndef PQUEUE */

