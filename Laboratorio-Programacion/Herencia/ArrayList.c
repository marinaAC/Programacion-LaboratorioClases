
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* pList;
    ArrayList* returnAux = NULL;
    void* pElements;
    pList=(ArrayList *)malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            pList->size=0;
            pList->pElements=pElements;
            pList->reservedSize=AL_INITIAL_VALUE;
            pList->add=al_add;
            pList->len=al_len;
            pList->set=al_set;
            pList->remove=al_remove;
            pList->clear=al_clear;
            pList->clone=al_clone;
            pList->get=al_get;
            pList->contains=al_contains;
            pList->push=al_push;
            pList->indexOf=al_indexOf;
            pList->isEmpty=al_isEmpty;
            pList->pop=al_pop;
            pList->subList=al_subList;
            pList->containsAll=al_containsAll;
            pList->deleteArrayList = al_deleteArrayList;
            pList->sort = al_sort;
            returnAux = pList;
        }
        else
        {
            free(pList);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this,void* pElement)
{
    int returnAux = -1;
    if(this != NULL && pElement != NULL){
        if(this->size < this->reservedSize){
            this->pElements[this->size] = pElement;
            //*((this->pElements)+(this->size))= pElement;
            this->size++;
        }
        if(this->size == this->reservedSize){
            resizeUp(this);
        }
        returnAux = 0;
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL){
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL){
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this , int index)
{
    void* returnAux = NULL;
//tiene que ser menor o igual a size
    if(this != NULL && index >=0 && index <= this->size){
        returnAux = this->pElements[index];
    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && pElement != NULL){
        returnAux = 0;
        int i;
        for(i=0;i<this->size;i++){
            if(this->pElements[i]==pElement){
                returnAux = 1;
                break;
            }
        }
    }
    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && pElement != NULL && index>=0 && index <= this->size){
        returnAux =0;
        this->pElements[index] = pElement;
    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    if(this != NULL && index>=0 && index<=this->size){
        int newSize;
        for(;index<this->size-1;index++){
            this->pElements[index] = this->pElements[index+1];
        }
        newSize=al_len(this);
        this->size = newSize-1;
        returnAux = 0;
    }
    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;
    if(this!=NULL){
        this->size = 0;
        //contract(this,this->size);
        returnAux = 0;
    }
    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    if(this!=NULL){
       int i;
       returnAux = al_newArrayList();
       for(i=0;i<this->size;i++){
            al_get(this,i);
            al_add(this,returnAux);
       }
    }
    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && index>=0 && index<= this->size && pElement != NULL){
        int i;
        al_add(this,pElement);
        for(i=this->size-1;i>=index;i--){
            if(this->pElements[i]==this->pElements[index]){
                this->pElements[i]=pElement;
            }
            this->pElements[i+1] = this->pElements[i];
        }
        returnAux = 0;
    }

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && pElement != NULL){
        int i;
        for(i=0;i<this->size;i++){
            if(this->pElements[i]==pElement){
                returnAux = i;
            }
        }
    }

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL){
        int i;
        returnAux = 1;
        for(i=0;i<this->size;i++){
           if(al_get(this,i)!= NULL){
                returnAux = 0;
           }
        }
    }
    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index>=0 && index<= this->size){
        returnAux = al_get(this,index);
        al_remove(this,index);
    }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    ArrayList* returnAux = NULL;
    ArrayList* newArrayList;
    void* pElement;
    int flag = 0;
    if(this!= NULL && to>=0 && to<=this->size && from>=0 && from<=this->size && from<to){
        newArrayList = al_newArrayList();
        if(newArrayList !=  NULL){
            for(;from<to;from++){
                pElement = al_get(this,from);
                if(al_add(newArrayList,pElement) !=0){
                        flag= 1;
                        break;
                }
            }
            if(flag==0){
                returnAux = newArrayList;
            }

        }
    }
    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* secondList)
{
    int returnAux = -1;
    void* pElement;
    if(this != NULL && secondList != NULL){
        int i;
        int findElement = 0;
        int notContains =0;
        int sizeSecondList = al_len(secondList);
        for(i=0; i < sizeSecondList; i++){
            pElement = al_get(secondList,i);
            if(al_contains(this,pElement)==1){
                  findElement++;
            }else if(al_contains(this,pElement)==0){
                notContains++;
            }

            if(findElement == sizeSecondList){
                returnAux = 1;
            }
            if(notContains>0){
                returnAux = 0;
            }

        }
    }

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int i;
    void* aux;
    int flag = 0;
    if(this != NULL, pFunc != NULL){
        int sizeList = al_len(this)-1;
        while(flag==0){
            flag=1;
            returnAux =0;
            if(order == 1){
                    for(i=0;i<sizeList;i++){
                        aux = this->pElements[i];
                        this->pElements[i]=this->pElements[i+1];
                        this->pElements[i+1]=aux;
                        flag=0;
                    }
            }else if(order == 0){
                    for(i=0;i<sizeList;i++){
                        aux=this->pElements[i+1];
                        this->pElements[i+1]=this->pElements[i];
                        this->pElements[i]=aux;
                        flag=0;
                    }
               }else{
                    returnAux = -1;
               }
            }
        }
    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL){
        void* aux = realloc(this->pElements,sizeof(void*)*(this->reservedSize+AL_INCREMENT));
        if(aux != NULL){
            this->pElements = aux;
            this->reservedSize = this->reservedSize + AL_INCREMENT;
            returnAux = 0;
        }
    }
    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;
    if(this != NULL && index >= 0 && index < this->size){
        if(this->size < this->reservedSize || resizeUp(this) == 0){
            this->size++;
            int i;
            for(i = (this->size)-1; i > index; i--)
                this->pElements[i] = this->pElements[i-1];
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;
       while(index < (this->size)-1){
            this->pElements[index] = this->pElements[index+1];
            index++;
        }

        (this->size)--;
    return returnAux;
}

