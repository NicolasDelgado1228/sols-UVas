def solve(heights, widths, n):
    ans1, ans2, i = widths[0], widths[0], 1
    tab1, tab2 = [widths[x] for x in range(n)], [widths[x] for x in range(n)]

    while(i < n):
        for j in range(i):
            if(heights[j] < heights[i]):
                tab1[i] = max(tab1[i], tab1[j]+widths[i])
            if(heights[j] > heights[i]):
                tab2[i] = max(tab2[i], tab2[j]+widths[i])
        ans1, ans2 = max(ans1, tab1[i]), max(ans2, tab2[i])
        i += 1
    
    return (ans1, ans2)




def main():
    cases = int(input())
    for case in range(1, cases+1):
        n = int(input())

        heights = list(map(int, input().split()))
        widths = list(map(int, input().split()))

        increasing, decreasing = solve(heights, widths, len(widths))

        if(increasing >= decreasing):
            print("Case " + str(case) + ". Increasing (" + str(increasing) + "). Decreasing (" + str(decreasing) + ").")
        else:
            print("Case " + str(case) + ". Decreasing (" + str(decreasing) + "). Increasing (" + str(increasing) + ").")


main()