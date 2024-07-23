We can solve this just using math. Initially we have 10! combinations for 10 digits and we are looking for 1,000,000 in the range of [0,10!]
Hence consider cases:

```
| digit 0 for range 0 -> 362,880 (since the first 362,880 permutations all start with 0)
| digit 1 for range 362,880 -> 725760 (since the next 362,880 permutations all start with 1)
| digit 2 for range 725760 -> 1088640
```

We find that 1,000,000 is in the range of digit 2 and so take 2 as the first digit, repeat interpolation between 725760 and 1088640,
with remaining digits in order to get 7 as next digit, then 8, 3, 9 etc...

Giving us:
__2783915460__
