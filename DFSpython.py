
GRAPH = {
    '1': set(['2', '3']),
    '2': set(['1', '4', '5']),
    '3': set(['1']),
    '4': set(['2']),
    '5': set(['3', '4'])
}
Visit = set()

def DFS(Visit, GRAPH, NODE):
    if NODE not in Visit:
        print(NODE)
        Visit.add(NODE)
        for n in GRAPH[NODE]:
            DFS(Visit, GRAPH, n)

print("Depth-First-Search")
DFS(Visit, GRAPH, '1')
