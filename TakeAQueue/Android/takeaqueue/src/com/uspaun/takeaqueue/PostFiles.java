package com.uspaun.takeaqueue;

import java.util.ArrayList;

public class PostFiles {
	public String URL;
	public ArrayList<String> Names = new ArrayList<String>();
	public ArrayList<String> Files = new ArrayList<String>();
	public void Set(String Name, String File)
	{
		Names.add(Name);
		Files.add(File);
	}
}
