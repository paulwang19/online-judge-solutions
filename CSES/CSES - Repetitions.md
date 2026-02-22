# CSES - Repetitions

## 程式碼

```py
if __name__ == "__main__":
    s = input()
    cur_rep = 0
    max_rep = 1
    last_ch = ''
    for cur_ch in s:
        if cur_ch == last_ch:
            cur_rep += 1
            if cur_rep > max_rep:
                max_rep = cur_rep
        else:
            cur_rep = 1
            last_ch = cur_ch
    
    print(max_rep)
```
