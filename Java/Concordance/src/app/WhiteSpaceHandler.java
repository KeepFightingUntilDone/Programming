package src.app;

import java.util.HashMap;

public class WhiteSpaceHandler extends Handler {

	@Override
	public void HandleRequest(String request, String nextWord, HashMap<String, ConcordanceDataStruct> concordance) {
		// TODO Auto-generated method stub
		if (request.trim().isEmpty())
		{
			return;
		}
		else
		{
			this.successor.HandleRequest(request, nextWord, concordance);
		}
	}

}
