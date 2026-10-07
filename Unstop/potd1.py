
def calculate_riskiest_tube(n, m, edges):
    import heapq
    graph = [[] for _ in range(n + 1)]

    for u, v, w in edges:
        graph[u].append((v, w))
        graph[v].append((u, w))
    danger = [float('inf')] * (n + 1)
    danger[1] = 0

    pq = [(0, 1)]

    while pq:
        current_danger, u = heapq.heappop(pq)

        if current_danger > danger[u]:
            continue

        for v, w in graph[u]:
            new_danger = max(current_danger, w)

            if new_danger < danger[v]:
                danger[v] = new_danger
                heapq.heappush(pq, (new_danger, v))
    result = []

    for i in range(1, n + 1):
        if danger[i] == float('inf'):
            result.append(-1)
        else:
            result.append(danger[i])

    return result


def main():
    import sys

    input = sys.stdin.read
    data = input().strip().split()

    n = int(data[0])
    m = int(data[1])

    edges = []
    index = 2

    for _ in range(m):
        u = int(data[index])
        v = int(data[index + 1])
        w = int(data[index + 2])

        edges.append((u, v, w))
        index += 3

    result = calculate_riskiest_tube(n, m, edges)

    print(" ".join(map(str, result)))


if __name__ == "__main__":
    main()

