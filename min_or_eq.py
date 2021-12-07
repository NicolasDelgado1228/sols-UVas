def less_or_eq(a, b):
    if len(a) < len(b):
        for i in range(len(a)):
            if a[i] != b[i]: return a[i] <= b[i]
    else:
        for i in range(len(b)):
            if a[i] != b[i]: return a[i] <= b[i]
    return len(a) <= len(b)

def  more_or_eq(a, b):
    if len(a) < len(b):
        for i in range(len(a)):
            if a[i] != b[i]: return a[i] >= b[i]
    else:
        for i in range(len(b)):
            if a[i] != b[i]: return a[i] >= b[i]
    return len(a) >= len(b)
