/*
 * �ж�101-200֮���ж��ٸ���������������������������ֽ����������ǳ���1��������֮�⣬��û�������ܱ�������������Ҳ��������ֻ���������ӡ�����PriNum
 */
public class PriNum {
	public static void main(String[] args) {
		int count = 0;
		for(int i = 101;i<=200;i++){
			for(int j = 2;j <= Math.sqrt(i);j++){
				if(i % j == 0){
					count++;
					break;
				}
			}
		}
		System.out.println("101-200֮����"+count+"������");
	}
}
