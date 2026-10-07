
def process_events(N, Q, arr, events):

    values = sorted(set(arr))
    index_map = {value: i + 1 for i, value in enumerate(values)}

    left = [0]
    right = [0]
    count = [0]

    roots = [0] * (N + 1)

    def update(old, start, end, pos):
        new = len(count)

        left.append(left[old])
        right.append(right[old])
        count.append(count[old] + 1)

        if start != end:
            mid = (start + end) // 2

            if pos <= mid:
                left[new] = update(left[old], start, mid, pos)
            else:
                right[new] = update(right[old], mid + 1, end, pos)

        return new

    for i in range(1, N + 1):
        pos = index_map[arr[i - 1]]
        roots[i] = update(roots[i - 1], 1, len(values), pos)

    def kth(root_r, root_l, start, end, k):

        if start == end:
            return values[start - 1]

        mid = (start + end) // 2

        left_count = count[left[root_r]] - count[left[root_l]]

        if k <= left_count:
            return kth(
                left[root_r],
                left[root_l],
                start,
                mid,
                k
            )
        else:
            return kth(
                right[root_r],
                right[root_l],
                mid + 1,
                end,
                k - left_count
            )

    bit = [0] * (N + 1)
    flagged = [0] * (N + 1)

    def add(i, value):
        while i <= N:
            bit[i] += value
            i += i & -i

    def prefix_sum(i):
        total = 0

        while i > 0:
            total += bit[i]
            i -= i & -i

        return total

    answer = []

    for event in events:

        if event[0] == "RANK":
            _, l, r, k = event

            result = kth(
                roots[r],
                roots[l - 1],
                1,
                len(values),
                k
            )

            answer.append(result)

        elif event[0] == "FLAG":
            _, i = event

            # Toggle flag
            if flagged[i] == 0:
                flagged[i] = 1
                add(i, 1)
            else:
                flagged[i] = 0
                add(i, -1)

        elif event[0] == "AUDIT":
            _, l, r = event

            result = prefix_sum(r) - prefix_sum(l - 1)

            answer.append(result)

    return answer

N, Q = map(int, input().split())

arr = list(map(int, input().split()))

events = []

for _ in range(Q):

    data = input().split()

    if data[0] == "RANK":
        l = int(data[1])
        r = int(data[2])
        k = int(data[3])

        events.append(("RANK", l, r, k))

    elif data[0] == "FLAG":
        i = int(data[1])

        events.append(("FLAG", i))

    elif data[0] == "AUDIT":
        l = int(data[1])
        r = int(data[2])

        events.append(("AUDIT", l, r))

results = process_events(N, Q, arr, events)

for x in results:
    print(x)
