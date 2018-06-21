# 异步IO
所谓「异步 IO」，就是你发起一个 IO 操作，却不用等它结束，你可以继续做其他事情，当它结束时，你会得到通知。

可交给 asyncio 执行的任务，称为协程（coroutine）。一个协程可以放弃执行，把机会让给其它协程（即 yield from 或 await）。

在日常的使用中，我们会遇到的IO主要有：磁盘读写IO以及网络IO，使用asyncio可以帮助我们更加高效的使用资源，提高程序的响应，而不是让程序顺序排队等在IO上。

# 定义协程
```python
import asyncio
async def do_some_work(x):
    pass
```
do_some_work 便是一个协程。准确来说，do_some_work 是一个协程函数。
```python
>>> print(asyncio.iscoroutinefunction(do_some_work))
True
```

# 最简单的使用
```python
import asyncio
async def myfun(i):
    print('start {}th'.format(i))
    await asyncio.sleep(1)
    print('finish {}th'.format(i))

loop = asyncio.get_event_loop()
myfun_list = (myfun(i) for i in range(10))
loop.run_until_complete(asyncio.gather(*myfun_list))
```
