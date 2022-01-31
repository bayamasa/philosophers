忘れないように完成したあとに網羅的にチェックするテストケースを書いておくメモ

time系は0を許容するのか
optionは0を許容するのか

mutex.lockの中でmutex.lockをかけるとどうなるのか￥
→ deadlockする。

sleepの時間変えたらbus errorなおった
simulation.c L50 usleep 200→20
simulation.c L23 usleep 50→削除

unlock → robust unlockにしたほうがいいかも

とあるスレッド: 2が食べてから帰ってきてない。deadlockか？

1643668011388242 1 has taken a fork
1643668011388290 1 is eating
1643668011388479 1 is sleeping
1643668011388479 2 has taken a fork
1643668011388579 2 is eating
→こっから帰ってきてない
1643668011388744 1 is thinking
1643668011388976 1 died

