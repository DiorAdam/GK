

def colorGraph(G):
    color = {}
    for w in G:
        if w in color:
            continue
        Link = [w]
        color[w] = 0
        while Link:
            u = Link.pop()
            for v in G[u]:
                if v not in color:
                    color[v] = 1-color[u]
                    Link.append(v)
                elif color[v] == color[u]:
                    return False
    return True




T = int(input())
for t in range(1, T+1):
    N = int(input())
    s = [-1] + list(input())
    G = {}
    for i in range(5, len(s)):
        

