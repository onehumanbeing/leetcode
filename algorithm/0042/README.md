这道题的思路是采用l和r两个指针，维护装水两边的位置。

当l处高度低时，说明l右侧装的水肯定和l处一样高，此时逐步右移l，同是加上l处与右移后位置高度差（因为这里都能装水啊），直到再遇到同样高或者更高的位置。然后进行下一轮判断。

同样，当r处高度低时，说明r左侧的水肯定和r处一样高，此时逐步左移r，同是加上r处与左移后位置高度差，直到再遇到同样高或者更高的位置。

最后直到l和r相遇，结束。