# include <stdio.h>
# include <stdlib.h>

int maxSumIS(int *arr, int n);

int main()
{
    int n, max, i; //sum, max, i, j, prev;
    int *a;
    
    scanf("%d", &n);
    
    a = (int *)malloc(n * sizeof(int));
    
    for(i = 0; i < n; i++)
    {
        scanf("%d", a+i);
    }
    
//     max = a[0];
    
//     for(i = 1; i < n; i++)
//     {
//         if(max < a[i])
//             max = a[i];
//     }
    
//     for(i = 0; i < n; i++)
//     {
//         sum = a[i];
//         prev = a[i];
        
//         for(j = i + 1; j < n; j++)
//         {
//             if(a[j] > prev)
//             {
//                 sum += a[j];
//                 prev = a[j];
//                 if(max < sum)
//                 {
//                     max = sum;
//                 }
//             }
//         }
//     }
    
    max = maxSumIS(a, n);
    
    printf("%d", max);
    
    return 0;
}


int maxSumIS(int *arr, int n) 
{ 
    int i, j, max = 0; 
    int *msis; 

    msis = (int *)malloc(n * sizeof(int));

    for ( i = 0; i < n; i++ )
    { 
        msis[i] = arr[i];
    }

    for ( i = 1; i < n; i++ ) 
    {
        for ( j = 0; j < i; j++ ) 
        {
            if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i]) 
            {    
                msis[i] = msis[j] + arr[i];
            }
        }
    }
    
    for ( i = 0; i < n; i++ )
    { 
        if ( max < msis[i] )
        { 
            max = msis[i];
        }
    }

    return max; 
} 

