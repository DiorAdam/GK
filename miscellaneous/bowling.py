

def max_score_recursive(pins: list[int]) -> int:
    n = len(pins)
    mem: dict[int, int] = {n-1: pins[n-1] if pins[n-1] > 0 else 0, n: 0}
    def rec(start: int):
        if start in mem:
            return mem[start]
        score = max(pins[start] + rec(start+1), rec(start+1), pins[start]*pins[start+1] + rec(start+2))
        mem[start] = score
        return score
    return rec(0)

def max_score_iterative(pins: list[int]) -> int:
    states = [0, pins[0] if pins[0] > 0 else 0]
    for i in range(1, len(pins)):
        score = max(states[i], states[i] + pins[i], states[i-1] + pins[i]*pins[i-1])
        states.append(score)
    return states[-1]


if __name__ == "__main__":
    pins = [-3, 1, 1, 9, 9, 2, -5, -5]
    print(max_score_recursive(pins))
    print(max_score_iterative(pins))
