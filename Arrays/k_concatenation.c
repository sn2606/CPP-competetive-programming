# include <stdio.h>
# include <stdlib.h>

int maxi(int *a, int n);

int main()
{
    int n, k, i, j = 0, max_neg; 
    long long sum = 0;
    int *a;

    printf("Enter n: ");    
    scanf("%d", &n);

    printf("Enter k: ");
    scanf("%d", &k);
    
    a = (int *)malloc(n * sizeof(int));
    
    printf("Enter array: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", a + i);        
    }
    
    for(i = n-1; i >= 0; i--)
    {
        if(a[i] < 0)
        {
            j = i;
            break;
        }
    }
    
    printf("j = %d\n", j);
    max_neg = a[j];
    
    while(j < n && k != 0)
    {
        j = (j + 1) % n;
        if(j == 0)
            k--;
        if(a[j] >= 0)
        {
            sum += a[j];
        }
        else 
            break;
    }
    
    int maxi(int *a, int n);
    
    if(sum == 0)
    {
        for(i = 0; i < n; i++)
        {
            if(a[i] > 0)
                sum += a[i];            
        }
    }

    if(sum < maxi(a, n))
        sum = maxi(a, n);
    
    if(sum == 0)
        sum = max_neg;
    
    printf("%d", sum);
    
    return 0;
    
}

int maxi(int *a, int n)
{
    int i;
    int m = a[0];

    for(i = 0; i < n; i++)
    {
        if(m < a[i])
        {
            m = a[i];
        }
    }

    return m;
}