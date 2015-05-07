package laba3;

import java.util.Random;

import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.List;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;

public class zdacha {

	protected Shell shell;
	private Text text;

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			zdacha window = new zdacha();
			window.open();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * Open the window.
	 */
	public void open() {
		Display display = Display.getDefault();
		createContents();
		shell.open();
		shell.layout();
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch()) {
				display.sleep();
			}
		}
	}

	/**
	 * Create contents of the window.
	 */
	protected void createContents() {
		shell = new Shell();
		shell.setSize(370, 273);
		shell.setText("SWT Application");
		
		Label label = new Label(shell, SWT.NONE);
		label.setText("Size:");
		label.setBounds(10, 16, 33, 15);
		
		text = new Text(shell, SWT.BORDER);
		text.setBounds(49, 10, 76, 21);
		
		List list = new List(shell, SWT.BORDER);
		list.setBounds(10, 59, 164, 141);
		
		List list_1 = new List(shell, SWT.BORDER);
		list_1.setBounds(185, 59, 164, 141);
		
		Button button = new Button(shell, SWT.NONE);
		button.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				list.removeAll();
				list_1.removeAll();
				findMax(Integer.parseInt(text.getText()));
			}
			
			public void findMax(int r)
			{
				Random rand = new Random();
				int[][] matrix = new int[r][r];
				//int[][] nmat = new int[r][r];
				for (int i = 0; i < matrix.length; i++) {
				  matrix[i] = new int[r];
				  for (int j = 0; j < matrix.length; j++) {
				    matrix[i][j] = -i;
				  }
				}
				//for (int i = 0; i < nmat.length; i++) {
					  //nmat[i] = new int[r];
					  //for (int j = 0; j < nmat.length; j++) {
					   // nmat[i][j] = -i;
					  //}
					//}
				for (int i = 0; i < matrix.length; i++) {
					for (int j = 0; j < matrix.length; j++) {
						matrix[i][j]=rand.nextInt(10);
					}
				}
				String mst="";
				for (int i = 0; i < matrix.length; i++) {
					for (int j = 0; j < matrix.length; j++) {
						mst+=Integer.toString(matrix[i][j])+" ";
					}
					list.add(mst);
					mst="";
				}
				int counter=0;
				int buf=0;
				String scnd="";
				list_1.removeAll();
				for (int i = 0, i1=r-1; i < r/2; i++, i1--)
				{
					for (int j = i, j1=i1; j < r/2; j++, j1--)
					{
						
							buf = matrix[i][j];
							matrix[i][j]=matrix[i1][j1];
							matrix[i1][j1]=buf;
					}
				}
				mst="";
				
				for (int i = 0; i < matrix.length; i++) {
					for (int j = 0; j < matrix.length; j++) {
						mst+=Integer.toString(matrix[i][j])+" ";
					}
					list_1.add(mst);
					mst="";
				}
			}
		});
		button.setText("New Button");
		button.setBounds(10, 204, 75, 25);

	}

}