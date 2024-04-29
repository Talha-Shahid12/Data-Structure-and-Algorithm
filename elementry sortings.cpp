#include<iostream>
using namespace std;
void bubbleSort(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(arr[i]>arr[j])
            {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            }
        }
    }
}

void insertionSort(int *arr, int size)
{
    int key;
    int j=0;
    for(int i=1; i<size; i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>=key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void mergeSort(int *arr, int low ,int high)
{
    int mid;
    if(low<high)
    {
        mid = (high+low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);

    int size=high;
    int i=low;
    int j=mid+1;
    int k=0;
    int temp[high-low+1];
    while(i<=mid && j<=high)
    {
        if(arr[i] < arr[j])
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
while(i<=mid)
    temp[k++]=arr[i++];

while (j<=high)
    temp[k++]=arr[j++];

for(int i=low; i<=size; i++)
{
    arr[i]=temp[i-low];
}
    }
}


void selectionSort(int *arr, int size)
{
    int min_indx;
    for(int i=0; i<size; i++)
    {
        min_indx=i;
        for(int j=i+1; j<size; j++)
        {
            if(arr[j]<arr[min_indx])
            {
                min_indx=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min_indx];
        arr[min_indx]=temp;
    }
}

void combSort(int *arr, int size)
{
    int gap=size;
    while (gap!=1)
    {
        /* code */
        gap=gap/1.3;
        if(gap<1)
        {
            gap=1;
        }
        for(int i=0; i<size-gap; i++)
        {
            if(arr[i]>arr[i+gap])
            {
            swap(arr[i],arr[i+gap]);
            }
        }
    }
    
}

void printArray(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
     int choice;
     cout<<"\n\nadd shell and quick\n\n1- Bubble Sort\n2- Insertion Sort\n3- Selection Sort\n4- Comb Sort\n5- Merge Sort\nEnter Your Choice : ";
     cin>>choice;
    int size=5;
    int arr[size]={9,1,7,4,3}; 
    switch(choice)
    {
        case 1:
        	cout<<"\n\nArray Before Sorting.....\n";
        	printArray(arr,size);
            bubbleSort(arr,size);
            cout<<"\n\nArray After sorting.......\n";
            printArray(arr,size);
            break;
            case 2:
            	cout<<"\n\nArray Before Sorting.....\n";
            	printArray(arr,size);
                insertionSort(arr,size);
                cout<<"\n\nArray After Sorting.....\n";
                printArray(arr,size);
                break;
                case 3:
                	cout<<"\n\nArray Before Sorting.....\n";
                	printArray(arr,size);
                    selectionSort(arr,size);
                    cout<<"\n\nArray After Sorting.....\n";
                    printArray(arr,size);
					break;
                    case 4:
                    	cout<<"\n\nArray Before Sorting.....\n";
                    	printArray(arr,size);
                        combSort(arr,size);
                        cout<<"\n\nArray After Sorting.....\n";
                        printArray(arr,size);
						break;
                        case 5:
                        	cout<<"\n\nArray Before Sorting.....\n";
                        	printArray(arr,size);
                            mergeSort(arr,0,size);
                            cout<<"\n\nArray After Sorting.....\n";
                            printArray(arr,size);
							break;
                                default:
                            	cout<<"Invalid choice!";
                                break;
    }
}
