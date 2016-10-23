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
	static class node {
		node[] child = new node[26];
		char c = '0';
		int statistic = 0;

		public node() {
		}

		public node(char c) {
			this.c = c;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		node root = new node();
		node childNode = root;
		String str;
		for (int i = 0; i < N; i++) {
			str = s.next();
			for (int j = 0; j < str.length(); j++) {
				if (childNode.child[str.charAt(j) - 'a'] == null) {
					childNode.child[str.charAt(j) - 'a'] = new node(str.charAt(j));
				}
				childNode = childNode.child[str.charAt(j) - 'a'];
				childNode.statistic ++;
			}
			childNode = root;
		}
		
		int M = s.nextInt();
		int[] ans = new int[M];
		for(int i = 0 ; i < M ; i++){
			childNode = root;
			str = s.next();
			for(int j = 0; j < str.length(); j++){
				if(childNode.child[str.charAt(j) - 'a'] != null) {
					childNode = childNode.child[str.charAt(j) - 'a'];
					ans[i] = childNode.statistic;
				}
				else{
					ans[i] = 0;
					break;
				}
			}
		}

		for (int i = 0; i < M; i++)
			System.out.println(ans[i]);
		s.close();
	}
}
