
from cgi import print_arguments


class Percent:
    def partition(self,l,low,high):
        pivot = l[low]
        cnt = 0
        for i in range(low+1,len(l)):          
            if (l[i] < pivot):
                cnt += 1
                
        pivotindex = low + cnt
        
        l[low], l[pivotindex] = l[pivotindex], l[low]  #swap

        i = low
        j = high
        while (i < pivotindex and j > pivotindex):
            if(l[i] <= pivot):
                i += 1
            if(l[j] >= pivot):
                j -= 1
            elif(i < pivotindex and j > pivotindex):
                l[i], l[j] = l[j], l[i]
                i += 1
                j -= 1
        return pivotindex

    def QuickSort(self,l,low,high):
        if(low <= high):
            pi = self.partition(l,low,high)
            temp = high
            high = pi - 1
            self.QuickSort(l,low,high)
            high = temp
            low = pi + 1
            self.QuickSort(l,low,high)
        
           



def inputlist():
    search = Percent()
    list = []
    n = int(input("Enter the no. students : "))
    print("Enter the percentage of students : ")
    for i in range(n):
        r = float(input())
        list.append(r)
    print("This is the list of percentage of students :")
    print(list)

    search.QuickSort(list,0,n-1)
    l2=[]
    
    print("---------------------------------------")
    print("Percentage of top five students are :")
    for i in range(-1, -6, -1):
        l2.append(list[i])
    print(l2)


inputlist()  
