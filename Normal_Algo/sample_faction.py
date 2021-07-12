class Solution:
    def fractionToDecimal(self, numerator, denominator) :
        res = ""
        if numerator%denominator is 0:
            res = str(numerator//denominator)
        else:
            if (numerator<0 and denominator>0) or (numerator>0 and denominator<0):
                res = "-"
            before_decimal = numerator//denominator
            res = res + str(before_decimal)
            current_remainder = numerator%denominator
            after_decimal = []
            count = 0
            remainder_map = {}
            ans = ""
            while(current_remainder is not 0):
                if current_remainder in remainder_map.keys():
                    front = back = ""
                    for i in range(remainder_map[current_remainder]):
                        front += str(after_decimal[i])

                    for i in range(remainder_map[current_remainder], len(after_decimal)):
                        back += str(after_decimal[i])

                    ans = res + "." + front + "(" + back + ")"
                    break
                remainder_map[current_remainder] = count
                current_remainder *= 10
                after_decimal.append(current_remainder//denominator)
                current_remainder %= denominator
                count += 1

            if ans :
                res = ans
            else:
                decimal_str = ""
                for i in range(len(after_decimal)):
                    decimal_str += str(after_decimal[i])

                res = res + "." + decimal_str

        return res


if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		numerator, denominator = input().split()
		numerator = int(numerator); denominator = int(denominator)
		ob = Solution()
		ans = ob.fractionToDecimal(numerator, denominator)
		print(ans)
