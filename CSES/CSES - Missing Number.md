# CSES - Missing Number

## 程式碼

```py
if __name__ == "__main__":
    n = int(input())
    numbers = [int(num_str) for num_str in input().split()]

    number_set = set(range(1, n + 1))
    for num in numbers:
        number_set.remove(num)
    
    print(number_set.pop())
```
