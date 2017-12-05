#include <stdio.h>
#include <stdlib.h>
/*
 * Made by Yashasvi Goel
 * Enter the string from which words are to be extracted;
 * the output is enclosed in ':';
 * Thu Oct 12 09:05:39 IST 2017
*/
int* mergeSort(int *left,int *right,int l,int r)
{
	int i,j,k;
	i=j=k=0;
	int *c;
	c=(int*)malloc((l+r)*sizeof(int));
	while(i<l&&j<r)
	{
		if(left[i]<right[j])
			c[k++]=left[i++];
		else
			c[k++]=right[j++];
	}
	while(i<l)
		c[k++]=left[i++];
	while(j<r)
		c[k++]=right[j++];
	return c;
}
int* subArrays(int *r,int n)
{
	if(n<2)
		return r;
	int mid=n/2;
	int *left;
	left=(int*)malloc(mid*sizeof(int));
	int *right;
	right=(int*)malloc((n-mid)*sizeof(int));
	for(int i=0;i<mid;i++)
		*(left+i)=r[i];
	for(int j=mid,i=0;j<n;j++,i++)
		*(right+i)=r[j];
	left=subArrays(left,mid);
	right=	subArrays(right,n-mid);
	int *q;
	q=(int*)malloc(n*sizeof(int));
	q=mergeSort(left,right,mid,n-mid);
	return q;
}
int main()
{
	int n;
	scanf("%d",&n);
	int *r;
	r=(int*)malloc(n*sizeof(int));
	int *left,*right;
	for(int i=0;i<n;i++)
		scanf("%d",&r[i]);
	r=subArrays(r,n);
	int *y;
	for(int i=0;i<n;i++)
		printf("%d ",r[i]);
	return 0;
}
