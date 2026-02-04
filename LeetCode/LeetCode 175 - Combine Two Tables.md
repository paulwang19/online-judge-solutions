# LeetCode 175 - Combine Two Tables

## 程式碼

```sql
/* Write your T-SQL query statement below */
SELECT [firstName], [lastName], [city], [state]
FROM [Person]
LEFT JOIN [Address] ON [Person].personId = [Address].personId;
```
