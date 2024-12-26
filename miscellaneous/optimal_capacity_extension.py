
def oce(demand_py, cost_py, max_py, fixed_cost):
    demand = demand_py[-1]
    states = {0: 0}
    n = len(demand_py)
    for y in range(n):
        min_st = demand_py[y]
        max_st = min(max(states.keys()) + max_py, demand_py[-1])
        new_states = dict()
        for st in range(min_st, max_st+1):
            cy = float("inf")
            for prev_st in states:
                built = st - prev_st
                if 0 <= built <= max_py:
                    fc = 0 if built==0 else fixed_cost
                    cy = min(cy, states[prev_st] + fc + built*cost_py[y])
            new_states[st] = cy
        states = new_states
        print(states)
    return states[demand]


def backward_oce(demand_py, cost_py, max_py, fixed_cost):
    demand = demand_py[-1]
    states = {demand: 0}
    n = len(demand_py)
    demand_py = [0]+demand_py
    for y in range(n-1, -1, -1):
        print(states)
        for st in range(demand_py[y-1], demand+1):
            cy = float("inf")
            for built in range(0, max_py+1):
                if st + built in states:
                    fc = 0 if built==0 else fixed_cost
                    cy = min(cy, states[st + built] + fc + built*cost_py[y])
            states[st] = cy
    return states[0]


if __name__ == "__main__":
    demand = [1, 2, 4, 6, 7, 8]
    cost = [5400, 5600, 5800, 5700, 5500, 5200]
    max_py = 3
    fixed_cost = 1500
    optimal_cost_forward = oce(demand, cost, max_py, fixed_cost)
    optimal_cost_backward = backward_oce(demand, cost, max_py, fixed_cost)
    print(optimal_cost_forward)
    print(optimal_cost_backward)
