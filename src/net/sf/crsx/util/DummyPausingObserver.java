/* Copyright © 2010 IBM Corporation. */

package net.sf.crsx.util;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import net.sf.crsx.Builder;
import net.sf.crsx.Observable;
import net.sf.crsx.Observer;
import net.sf.crsx.Term;
import net.sf.crsx.Valuation;

/**
 * Dummy observer that prints to standard output.
 * 
 * @author Takahide Nogayama
 * @version $Id: DummyPausingObserver.java,v 3.0 2012/12/17 18:04:58 krisrose Exp $
 */
public class DummyPausingObserver implements Observer
{
	public void update(Observable observable, Object[] observedObjects)
	{
		if (observable instanceof Builder)
		{
			Builder builder = (Builder) observable;
			Term parentTerm = (Term) observedObjects[0];
			Term termToBeRewritten = (Term) observedObjects[1];
			Valuation valuationToBeApplied = (Valuation) observedObjects[2];

			System.out.println("Builder=" + builder);
			System.out.println("ParentTerm=" + parentTerm);
			System.out.println("Term=" + termToBeRewritten);
			System.out.println("Valuation=" + valuationToBeApplied);
			System.out.println("Rule name=" + valuationToBeApplied.name());
			System.out.println();

			try
			{
				System.out.print("\n Program is paused. Start profiliing, then type enter:");
				BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
				String name = br.readLine();
			}
			catch (IOException e1)
			{
				e1.printStackTrace();
			}

			// simulate human task
			try
			{
				Thread.currentThread().sleep(1000);
			}
			catch (InterruptedException e)
			{
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		else
		{
			throw new IllegalArgumentException(Observable.class.getName() + " can not be cast to " + Builder.class.getName());
		}
	}
}
