# LeetCode 165 - Compare Version Numbers

## 程式碼

```py
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        revision_list1 = version1.split('.')
        revision_list2 = version2.split('.')
        len1 = len(revision_list1)
        len2 = len(revision_list2)
        revision_list1 += [0] * (max(len1, len2) - len1)
        revision_list1 = [int(s) for s in revision_list1]
        revision_list2 += [0] * (max(len1, len2) - len2)
        revision_list2 = [int(s) for s in revision_list2]
        for pair in zip(revision_list1, revision_list2):
            if pair[0] > pair[1]:
                return 1
            elif pair[0] < pair[1]:
                return -1
        return 0
```
