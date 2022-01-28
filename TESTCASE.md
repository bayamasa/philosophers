忘れないように完成したあとに網羅的にチェックするテストケースを書いておくメモ

time系は0を許容するのか
optionは0を許容するのか

mutex.lockの中でmutex.lockをかけるとどうなるのか￥
→ deadlockする。

sleepの時間変えたらbus errorなおった
simulation.c L50 usleep 200→20
simulation.c L23 usleep 50→削除

unlock → robust unlockにしたほうがいいかも
