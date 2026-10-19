
class Solution:
    def sumCounts(self, nums: list[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)

        
        size = 4 * n
        sums = [0] * size
        squares = [0] * size
        lazy = [0] * size

        def apply(node, l, r, val):
            length = r - l + 1

            squares[node] = (
                squares[node]
                + 2 * val * sums[node]
                + val * val * length
            ) % MOD

            sums[node] = (
                sums[node] + val * length
            ) % MOD

            lazy[node] += val

        def push(node, l, r):
            if lazy[node] == 0 or l == r:
                return

            mid = (l + r) // 2
            val = lazy[node]

            apply(node * 2, l, mid, val)
            apply(node * 2 + 1, mid + 1, r, val)

            lazy[node] = 0

        def update(node, l, r, ql, qr):
            if ql <= l and r <= qr:
                apply(node, l, r, 1)
                return

            push(node, l, r)
            mid = (l + r) // 2

            if ql <= mid:
                update(node * 2, l, mid, ql, qr)

            if qr > mid:
                update(node * 2 + 1, mid + 1, r, ql, qr)

            sums[node] = (
                sums[node * 2] + sums[node * 2 + 1]
            ) % MOD

            squares[node] = (
                squares[node * 2] + squares[node * 2 + 1]
            ) % MOD

        last = {}
        ans = 0

        for i, x in enumerate(nums):
            prev = last.get(x, -1)

            update(1, 0, n - 1, prev + 1, i)

            # subarrays ending at the current index
            ans = (ans + squares[1]) % MOD

            last[x] = i

        return ans

        