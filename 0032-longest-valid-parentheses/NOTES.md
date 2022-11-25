for (int j = i; j < n; j++)
{
if (s[j] == '(')
{
countOpen++;
}
else
{
countClose++;
}
​
int diff = countOpen - countClose;
/*
diff < 0
means that there are too many right parentheses. At this time, no matter what is behind it, it  must be an illegal string, so the loop can be ended early
*/
if (diff < 0)
{
break;
}
​
// diff == 0 means we have both equal open and equal close
if (diff == 0)
{
ans = max(ans, j - i + 1);
}
}
}
​
return ans;
}
};
```
​
​
​
​
​