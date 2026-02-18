# CSES - Weird Algorithm

## 程式碼

```py
def weird_algorithm(n):
    if n % 2 == 0:
        return n // 2
    else:
        return 3 * n + 1

if __name__ == "__main__":
    n = int(input())
    while n != 1:
        print(n, end=' ')
        n = weird_algorithm(n)
    print(n)
```
