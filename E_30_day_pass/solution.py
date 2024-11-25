n = int(input())

for i in range(n):
    x, y, a, b = map(int, input().split())
    # 30 day 7 * 4 = 28
    # so a > 20 and b > 8
    if a + b != 30 or b < 8 or a < 20 :
        print('Wrong Input')
    elif a * x + b * y == 1200 :
        print('Equally Good')
    elif a * x + b * y < 1200:
        print('Pay As You Go')
    elif a * x + b * y > 1200:
        print('30-Day Pass')