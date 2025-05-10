import subprocess
import os
import time

def main():
    # 创建无名管道
    r, w = os.pipe()

    # 启动子进程
    child_proc = subprocess.Popen(
        ['./child'],
        stdin = r,
        close_fds = True  #关闭所有无关文件描述符
    )

    # 父进程关闭读端
    os.close(r)

    try:
        while True:
            # 用户输入
            s = input("Enter a string (Ctrl+C to exit): ")
            # 打印python接收
            print(f'Python received: {s}')
            # 将输入转换为字节数据并添加换行
            data = (s + '\n').encode()
            # 将数据写入管道
            os.write(w, data)
            time.sleep(0.1)


    except KeyboardInterrupt:
        print("\nExiting...")
    finally:
        # 关闭管道
        os.close(w)
        child_proc.wait()

if __name__ == "__main__":
    main()
