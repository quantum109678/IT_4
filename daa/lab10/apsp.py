def fw(G,v):

    for k in range(v):

        for i in range(v):

            for j in range(v):

                G[i][j]=min(G[i][j],G[i][k]+G[k][j])

v=4
INF=9999
graph = [[0,5,INF,10],
             [INF,0,3,INF],
             [INF, INF, 0,   1],
             [INF, INF, INF, 0]
        ]
fw(graph,v)

for i in range(v):
    for j in range(v):
        if graph[i][j]!=INF:
            print(graph[i][j],end=" ")
        else:
            print("INF",end=" ")
    print()