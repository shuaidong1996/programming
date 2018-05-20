package com.dong.proxy;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

/**
 * ��Ҫ����Ľӿ�
 */
interface Worker {
	public void Add(int a, int b);
}

/**
 * ʵ�ʶ���
 */
class WorkerImpl implements Worker {

	@Override
	public void Add(int a, int b) {
		System.out.println(a + "+" + b + "=" + (a + b));
	}

}

/**
 * ���ô�����ʵ���� ÿ�����ɶ�̬���������ʱ����Ҫָ��һ��ʵ���˸ýӿڵĵ��ô���������
 */
class InvocationHandlerImpl {
	/**
	 * �����������Ҫ�������ʵ����
	 */
	private Object target;

	/**
	 * ���췽��
	 * 
	 * @param target
	 */
	public InvocationHandlerImpl(Object target) {
		super();
		this.target = target;
	}

	public Object getProxyInstance() {
		return Proxy.newProxyInstance(InvocationHandlerImpl.class
				.getClassLoader(), target.getClass().getInterfaces(),
				new InvocationHandler() {
					@Override
					public Object invoke(Object proxy, Method method,
							Object[] args) throws Throwable {
						// ��Ŀ�����ķ���ִ��֮ǰ�򵥵Ĵ�ӡһ��
						System.out
								.println("------------------before------------------");
						System.out.println("Method:" + method);
						// ִ��Ŀ�����ķ���
						Object result = method.invoke(target, args);
						// ��Ŀ�����ķ���ִ��֮��򵥵Ĵ�ӡһ��
						System.out
								.println("-------------------after------------------");
						return result;
					}
				});
	}
}

public class ProxyDemo {
	public static void main(String[] args) {
		// ʵ����Ŀ�����
		Worker worker = new WorkerImpl();
		// ʵ����InvocationHandler
		InvocationHandlerImpl invocationHandlerImpl = new InvocationHandlerImpl(
				worker);
		// ����Ŀ��������ɴ������
		Worker proxy = (Worker) invocationHandlerImpl.getProxyInstance();
		// ���ô������ķ���
		proxy.Add(10, 12);
	}
}
