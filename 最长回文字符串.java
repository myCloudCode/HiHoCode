import java.util.Scanner;

/**
 * 
 */

/**
 * @author CHRT
 * @date 2016年10月10日
 */
public class Main {

	/**
	 * @param args
	 */
	/*#include <cstdio>
	  #include <cstring>
	  #include <string.h>
      char str[1000002 + 1200];

	   int fast(char *p)
       {
     		int ans = 1;
    		for (int i = 1; p[i]; ++i)
    		{
        		int s = i, e = i, t;
        		while (p[e + 1] == p[i]) ++e;
        		i = e;
        		while (p[s - 1] == p[e + 1]) --s, ++e;
        		if ((t = e - s + 1) > ans) ans = t;
    		}
    		return ans;
		}

		int main()
		{
    		str[0]='$';
    		int n;
    		scanf("%d", &n);
    		while (n --) {
        		scanf("%s", str + 1);
        		printf("%d\n", fast(str));
    		}
    		return 0;
		}*/

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		int[] ans = new int[N];
		int temp;
		int l, t, n;
		for (int i = 0; i < N; i++) {
			temp = 1;
			String str = s.next();
			for (int j = 0 ; j < str.length() ; j++) {
				n = l = j;
				while (n + 1 < str.length() && str.charAt(n + 1) == str.charAt(j)){
					n++;
				}
				j = n;
				while(n + 1 < str.length() && l - 1 >= 0 && str.charAt(l - 1) == str.charAt(n + 1)){
					l--;
					n++;
				}
				if((t = n - l + 1) > temp) temp = t;
			}
			ans[i] = temp;
		}
		for(int i = 0 ; i < N ; i++)
			System.out.println(ans[i]);
		s.close();
	}
}
