# include <stdio.h>
# include <stdlib.h>

void generate_hash(int *a, int n, int s);
int search_hash(int *h, int b, int s);

int main() {
	//code
	
	int n, i, j;
	int *al1, *al2;
	int **a1, **a2, **h1;
	
	scanf("%d", &n);
	al1 = (int *)malloc(n * sizeof(int));
	al2 = (int *)malloc(n * sizeof(int));
	a1  = (int **)malloc(n * sizeof(int *));
	h1  = (int **)malloc(n * sizeof(int *));
	a2  = (int **)malloc(n * sizeof(int *));
	
	for(i = 0; i < n; i++)
	{
	    scanf("%d %d", al1 + i, al2 + i);
	    //printf("%d, %d\n", al1[i], al2[i]);
	    
	    *(a1 + i) = (int *)malloc(al1[i] * sizeof(int));
	    *(a2 + i) = (int *)malloc(al2[i] * sizeof(int));
	    
	    *(h1 + i) = (int *)malloc(al1[i] * sizeof(int));
	    
	    for(j = 0; j < al1[i]; j++)
	        h1[i][j] = -1;
	    
	    for(j = 0; j < al1[i]; j++)
	    {
	        scanf("%d", *(a1 + i) + j);
	        generate_hash(h1[i], a1[i][j], al1[i]);
	    }
	    for(j = 0; j < al2[i]; j++)
	    {
	        scanf("%d", *(a2 + i) + j);
	    }
	   for(j = 0; j < al1[i]; j++)
	       printf("j = %d  h = %d\n", j, h1[i][j]);
	}
	
	int flag;
	
	for(i = 0; i < n; i++)
	{
	    flag = 1;
	    for(j = 0; j < al2[i]; j++)
	    {
	        flag = search_hash(h1[i], a2[i][j], al1[i]);
	        if(flag == 0)
	        {
	            //printf("%d %d\n", a2[i][j], h1[i][5]);
	            printf("No\n");
	            break;
	        }
	    }
	    if(flag == 1)
	    {
	        printf("Yes\n");
	    }
	}
	
	//printf("Yes");
	
	return 0;
}



void generate_hash(int *a, int n, int s)
{
    int hash, i;
    
    hash = n % s;
    printf("hash = %d\n", hash);
    
    if(a[hash] == -1)
    {
        a[hash] = n;
    }
    else
    {
        for(i = (hash + 1) % s; i != hash; i = (i + 1) % s)
        {
            printf("i = %d  1\n", i);
            if(a[i] == -1)
            {
                printf("i = %d   2\n", i);
                a[i] = n;
                break;
            }
        }
    }
}


int search_hash(int *h, int b, int s)
{
    int search, i;
    
    search = b % s;
    
    if(h[search] == b)
    {
        return 1;
    }
    else
    {
        for(i = (search + 1) % s; i != search; i = (i + 1) % s)
        {
            if(h[i] == b)
            {
                return 1;
            }
        }
    }
    
    return 0;
}
