#include<stdio.h>
#include<string.h>


int main(){
int count,src_router,i,j,k,w,v,min;
int costm[100][100],dist[100],last[100],flag[100];
printf("Enter the no of routers");
scanf("%d",&count);
printf("Enter the cost matrix");
for (i=0;i<count;i++){
	for(j=0;j<count;j++){
		printf("\n%d->%d:",i,j);
		scanf("%d",&costm[i][j]);
		if(costm[i][j]<0)costm[i][j]=10000;
	}
}
printf("\n Enter the source router:");
scanf("%d",&src_router);
for(v=0;v<count;v++){
	flag[v]=0;
	last[v]=src_router;
	dist[v]=costm[src_router][v];
}
flag[src_router]=1;
for (i=0;i<count;i++){
	min=10000;
	for(w=0;w<count;w++){
	if(!flag[w])
		if(dist[w]<min){
		v=w;
		min=dist[w];
		}
	}
	flag[v]=1;
	for(w=0;w<count;w++){
		if(!flag[w])
			if(min + costm[v][w] < dist[w]) {
				dist[w] = min + costm[v][w];
				last[w] = v;
				}
		}
}
for(i=0;i<count;i++){
	printf("\n%d==>%d:Path taken:%d", src_router, i, i);
	w = i;
	while (w != src_router) {
		printf("\n<--%d", last[w]);
		w = last[w];
	}
	printf("\n Shortest path cost:%d", dist[i]);
}

}
