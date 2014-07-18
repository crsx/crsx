package net.sf.crsx;

import java.util.Map;

/**
 * Analyzes meta variable uses
 * 
 * @author villardl
 */
public interface MetaAnalyzer
{
	
	public void analyzeMetaUseContractum(Term original, Map<String, Integer> counts, Map<String, MetaAnalyzer> subAnalyzers);
	
	public void analyzeMetaUsePattern(Term original, Map<String, Integer> counts, Map<String, MetaAnalyzer> subAnalyzers);
	
}
