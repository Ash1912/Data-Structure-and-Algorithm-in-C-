#include<stdio.h>
#include<stdlib.h>

struct List{
	int vnum;
	struct List *next;
};

struct Graph{
	int V;
	struct List **Adj;
};

struct Graph *createGraph()
{
	int i,u,v;
	struct List *temp,*node;
	struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph));
	if(G == NULL)
	{
		printf("Memory Full");
		return(G);
	}
	printf("Enter number of vertices: ");
	scanf("%d",&G->V);
	G->Adj = (struct List **)malloc(G->V * sizeof(struct List *));
	for(i = 0; i < G->V; i++)
	{
		G->Adj[i] = (struct List*)malloc(sizeof(struct List));
		G->Adj[i]->vnum = i;
		G->Adj[i]->next = NULL;
	}
	for(u = 0; u < G->V; u++)
	{
		temp = G->Adj[u];
		while(1)
		{
			printf("Enter adjacent edges to Vertex%d or -1 to end list: ",u);
			scanf("%d",&v);
			if(v == -1)
				break;
			temp->next = (struct List*)malloc(sizeof(struct List));
			temp = temp->next;
			temp->vnum = v;
			temp->next = NULL;
		}	
	}
	return(G);
}

void printGraph(struct Graph *G)
{
	int v;
  	for (v = 0; v < G->V; v++) 
	{
    	struct List *temp = G->Adj[v];
    	printf("\nVertex%d:\n", v);
    	while(temp->next)
		{
      	printf("%d -> ", temp->vnum);
      	temp = temp->next;
    	}
    	printf("%d", temp->vnum);
    	printf("\n");
  	}
}

int main()
{
	struct Graph *G;
	G = createGraph();
	printGraph(G);
	return 0;
}


  

