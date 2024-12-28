from copy import copy
from collections import defaultdict


def dag_shortest_path(dag: dict[int, list], node: int):
    mem: dict[int, dict] = dict()
    def rec(node):
        if node in mem: return mem[node]
        ans = {}
        for child in dag[node]:
            sp = rec(child)
            sp[child] = 0
            sp = increment_distances(sp)
            ans = min_dict(ans, sp)
        mem[node] = ans
        return ans
    return rec(node)

def min_dict(dico1, dico2):
    ans = copy(dico1)
    for key in dico2:
        if key in dico1:
            ans[key] = min(dico1[key], dico2[key])
        else:
            ans[key] = dico2[key]
    return ans

def increment_distances(distances):
    return {node: dist+1 for node, dist in distances.items()}


if __name__ == "__main__":
    dag = defaultdict(list, {0: [1, 2], 1: [2, 6], 2: [3, 4, 5], 5: [6]})
    print(dag_shortest_path(dag, 0))
