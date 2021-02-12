#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct request{
    char *requestdata;
    int priority;
}requestdata;
requestdata a[20],b[20],c[20],d[20];
requestdata total[81];
int sz[6],n,flag1=0,flag2=0;
int compare(const void *p, const void *q){
    struct request *a=(struct request *)p;
    struct request *b=(struct request *)q;
    return strcmp(a->requestdata,b->requestdata);
}

void sortall(){
    qsort(total,n, sizeof(struct request),compare);
}

int lower_bound(char *x){
    sortall();
    int low=0,high=n-1,md=0;
    while(high-low>0){
        md=(high+low-1)/2;

        if(strcmp(total[md].requestdata,x)<0){
            low=md+1;
        } else if (strcmp(total[md].requestdata,x)>0){
            high=md-1;
        } else {high=md;}
    }
    return strcmp(total[high].requestdata,x)==0?high:-1;
}

int upper_bound(char *x){
    sortall();
    int low=0,high=n-1,mid=0;
    while(high-low>0){
        mid=(high+low+1)/2;
        if(strcmp(total[mid].requestdata,x)<0)low=mid+1;
        else if(strcmp(total[mid].requestdata,x)>0)high=mid-1;
        else if(strcmp(total[mid].requestdata,x)==0)low=mid;

    }
    return low;
}

void search_by_priorityandrequest(int priority,char *req){
	for(int i=0;i<sz[1];i++){
		if(strcmp(a[i].requestdata,req)==0&&(a[i].priority==priority)){
			printf(" Exist in index %d in list1\n",i);
			flag1=1;
		}
	}
	for(int i=0;i<sz[2];i++){
		if(strcmp(b[i].requestdata,req)==0&&b[i].priority==priority){
			printf(" Exist in index %d in list2\n",i);
			flag1=1;
		}
	}
	for(int i=0;i<sz[3];i++){
		if(strcmp(c[i].requestdata,req)==0&&c[i].priority==priority){
			printf(" Exist in index %d in list3\n",i);
			flag1=1;
		}
	}
	for(int i=0;i<sz[4];i++){
		if(strcmp(d[i].requestdata,req)==0&&d[i].priority==priority){
			printf(" Exist in index %d in list4\n",i);
			flag1=1;
		}
	}
}

void search_by_priority(int priority){
	for(int i=0;i<sz[1];i++){
		if(a[i].priority==priority){
		printf(" Exist in index %d in list1\n",i);
		flag2=1;

		}
	}
	for(int i=0;i<sz[2];i++){
		if(b[i].priority==priority){
		printf(" Exist in index %d in list2\n",i);
		flag2=1;

		}
	}
	for(int i=0;i<sz[3];i++){
		if(c[i].priority==priority){
		printf(" Exist in index %d in list3\n",i);
		flag2=1;

		}
	}
	for(int i=0;i<sz[4];i++){
		if(d[i].priority==priority)
		printf(" Exist in index %d in list4\n",i);
	}
}

void choosesearch(int x,char *name,int prio){

    int upper=0,lower=0;

        if(x==1){
        	upper=upper_bound(name);
        	lower=lower_bound(name);
        	if(lower==-1)printf("Does not Exist\n");
            printf(" Exist Between index %d and index %d\n",lower,upper);
        }
        else if(x==2){
            search_by_priorityandrequest(prio,name);
            if(!flag1)printf(" Does not Exist\n");
        }
        else if(x==3){
        	search_by_priority(prio);
        	if(!flag2)printf(" Does not Exist\n");
        }


}



int main() {
    int priority;
    printf(" Enter number of requests : \n");
    scanf("%d",&n);
	printf(" Enter priority 1- Critical, 2- High, 3- Medium, 4- Low, then request data :\n");
    char x[20];
    for(int i=0;i<n;i++){
        scanf("%d",&priority);
        scanf("%s", x);
        total[i].priority=priority;
        total[i].requestdata=malloc(strlen(x)+1);strcpy(total[i].requestdata,x);
        if(sz[1]<20){a[sz[1]].requestdata=malloc(strlen(x)+1);strcpy(a[sz[1]].requestdata,x);a[sz[1]].priority=priority;sz[1]++;}
        else if(sz[2]<20){b[sz[2]].requestdata=malloc(strlen(x)+1);strcpy(b[sz[2]].requestdata,x);b[sz[2]].priority=priority;sz[2]++;}
        else if(sz[3]<20){c[sz[3]].requestdata=malloc(strlen(x)+1);strcpy(c[sz[3]].requestdata,x);c[sz[3]].priority=priority;sz[3]++;}
        else if (sz[4]<20){d[sz[4]].requestdata=malloc(strlen(x)+1);strcpy(d[sz[4]].requestdata,x);d[sz[3]].priority=priority;sz[4]++;}
    }

    printf(" Enter choice for your search or select the two lists that will be joined :\n");
    printf("1) for search by request data\n");
    printf("2) for both priority and search data\n");
    printf("3) for priority only\n");
    printf("4) list 1 + list 2 \n");
    printf("5) list 1 + list 3 \n");
    printf("6) list 1 + list 4 \n");
    printf("7) list 2 + list 3 \n");
    printf("8) list 2 + list 4 \n");
    printf("9) list 3 + list 4 \n");

    int size1,size2;
    int t,p;
    scanf("%d",&t);
    switch(t){
        case 1:
        scanf("%s",x);
        choosesearch(1,x,0);
        break;
        case 2:
        scanf("%d",&p);
        scanf("%s",x);
        choosesearch(2,x,p);
        break;
        case 3:
        scanf("%d",&p);
        choosesearch(3,"",p);
    break;
            case 4:
        size1=sz[1];
        size2=sz[2];
        join ( a,size1,b,size2 );
    break;
    case 5:
        size1=sz[1];
        size2=sz[3];
        join ( a,size1,c,size2 );
    break;
    case 6:
        size1=sz[1];
        size2=sz[4];
        join ( a,size1,d,size2 );
    break;
    case 7:
        size1=sz[2];
        size2=sz[3];
        join ( b,size1,c,size2 );
    break;
    case 8:
        size1=sz[2];
        size2=sz[4];
        join ( b,size1,d,size2 );
    break;
    case 9:
        size1=sz[3];
        size2=sz[4];
        join (c,size1,d,size2);
    break;
    }

    printf(" To update the priority Enter your request : ");

    scanf("%s",x);
    update_priority_request(x);


    printf("\n To Print all requests in all lists :\n");
    for(int i=0;i<n;i++)
    printf("%d %s\n",total[i].priority,total[i].requestdata);


    printf("\n To Empty all the lists : \n");
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    memset(d, 0, sizeof d);
    printf(" The lists have been cleared");



    return 0;
}


void update_priority_request(char *Request)
{

    int new_priority;
    printf(" Enter new priority :\n");
    scanf("%d",&new_priority);
    for(int i=0;i<sz[1];i++){
        if(strcmp(a[i].requestdata,Request)==0){

            a[i].priority=new_priority;
        }
            printf("%d %s\n",a[i].priority,a[i].requestdata);

    }
    for(int i=0;i<sz[2];i++){
        if(strcmp(b[i].requestdata,Request)==0){

           b[i].priority=new_priority;
        }
            printf("%d %s\n",b[i].priority,b[i].requestdata);

    }
    for(int i=0;i<sz[3];i++){
        if(strcmp(c[i].requestdata,Request)==0){

            c[i].priority=new_priority;
        }
            printf("%d %s\n",c[i].priority,c[i].requestdata);

    }
    for(int i=0;i<sz[4];i++){
        if(strcmp(d[i].requestdata,Request)==0){

            d[i].priority=new_priority;
        }
            printf("%d %s\n",d[i].priority,d[i].requestdata);

    }
}

void join (requestdata x[], int m, requestdata y[], int c) {
    requestdata joined[21];
    printf("%d\n",c);
    printf("%d\n",m);

    if (m+c>21){
        printf(" The two lists can't fit in one list ");
        }
    else
        {
        for (int i=0;i<m;i++){
            joined[i].priority=x[i].priority;
            joined[i].requestdata=malloc(strlen(x[i].requestdata)+1);
            strcpy(joined[i].requestdata,x[i].requestdata);
        }

        int k = m;

        for (int i=0;i<c;i++){
            joined[k].priority=y[i].priority;
            joined[k].requestdata=malloc(strlen(y[i].requestdata)+1);
            strcpy(joined[k].requestdata,y[i].requestdata);
            k++;
        }
    }

    printf(" The New joined list is :\n");

    for(int i=0;i<m+c;i++){
            printf("%d ",joined[i].priority);
            printf("%s\n",joined[i].requestdata);
    }

}







