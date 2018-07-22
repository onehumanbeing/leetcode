和 326 类似

int类型的范围是32位的,它的最大值是2的31次方减1

```
from math import pow
print " || ".join([ "n=={num}".format(num=int(pow(2, i))) for i in range(31)   ])

```