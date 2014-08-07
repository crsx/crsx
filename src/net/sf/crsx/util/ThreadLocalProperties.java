/* Copyright (c) 2009, 2010 IBM Corporation. */

package net.sf.crsx.util;

import java.util.HashMap;
import java.util.Map;

/**
 * ThreadLocalProperties is invented for eclipse plugin utility. 
 * 
 * @author nogayama
 */
public class ThreadLocalProperties
{
	public static final String FILE_ENCODING = "file.encoding".intern();

	/* ********************************************************** */

	private static final ThreadLocal<Map<String, String>> THREAD_LOCAL_STRAGE = new ThreadLocal<Map<String, String>>();

	private static Map<String, String> getTLSProperties()
	{
		Map<String, String> map = THREAD_LOCAL_STRAGE.get();

		if (map == null)
		{
			map = new HashMap<String, String>();
			THREAD_LOCAL_STRAGE.set(map);
		}

		return map;
	}

	public static String getProperty(String key)
	{
		return getTLSProperties().get(key);
	}

	public static String setProperty(String key, String value)
	{
		return getTLSProperties().put(key, value);
	}
}
