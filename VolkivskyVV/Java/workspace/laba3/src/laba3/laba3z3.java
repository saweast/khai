package laba3;

import java.util.Random;

import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.List;

public class laba3z3 {

	protected Shell shell;
	private Text text;
	private Text text_1;

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			laba3z3 window = new laba3z3();
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
		shell.setSize(308, 268);
		shell.setText("SWT Application");
		
		Label lblRows = new Label(shell, SWT.NONE);
		lblRows.setBounds(10, 10, 33, 15);
		lblRows.setText("rows");
		
		text = new Text(shell, SWT.BORDER);
		text.setBounds(49, 4, 76, 21);
		
		Label lblColumns = new Label(shell, SWT.NONE);
		lblColumns.setBounds(135, 10, 55, 15);
		lblColumns.setText("columns");
		
		List list = new List(shell, SWT.BORDER);
		list.setBounds(14, 51, 197, 141);
		
		text_1 = new Text(shell, SWT.BORDER);
		text_1.setBounds(196, 4, 76, 21);
		
		Button btnNewButton = new Button(shell, SWT.NONE);
		btnNewButton.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				list.removeAll();
				changeCols(Integer.parseInt(text.getText()), Integer.parseInt(text_1.getText()));
			}
			
			public void changeCols(int r, int c)
			{
				Random rand = new Random();
				int[][] matrix = new int[r][c];
				for (int i = 0; i < matrix.length; i++) {
				  matrix[i] = new int[r];
				  for (int j = 0; j < matrix.length; j++) {
				    matrix[i][j] = -i;
				  }
				}
				for (int i = 0; i < matrix.length; i++) {
					for (int j = 0; j < matrix.length; j++) {
						matrix[i][j]=rand.nextInt(99);
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
				list.add("new matrix");
				int buf=0;
				for(int i=0;i<matrix.length;i++) 
			    { 
			        buf=matrix[i][0];
			        matrix[i][0]=matrix[i][1];
			        matrix[i][1]=buf;
			    }
				for (int i = 0; i < matrix.length; i++) {
					for (int j = 0; j < matrix.length; j++) {
						mst+=Integer.toString(matrix[i][j])+" ";
					}
					list.add(mst);
					mst="";
				}
			}
		});
		btnNewButton.setBounds(10, 198, 75, 25);
		btnNewButton.setText("New Button");


		
	}
}
