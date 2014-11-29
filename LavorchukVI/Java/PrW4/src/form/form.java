package form;

import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.List;
import org.eclipse.jface.viewers.ListViewer;

public class form {
	private static Text text;
	private static Text text_1;
	private static Text text_2;
	private static Text text_3;
	private static Text text_4;
	private static Text text_5;

	public static void main(String[] args) {
		Display display = Display.getDefault();
		Shell shell = new Shell();
		shell.setSize(450, 215);
		shell.setText("SWT Application");
		
		Group group = new Group(shell, SWT.NONE);
		group.setText("\u0427\u0430\u0441\u0442\u0438\u043D\u0430 1");
		group.setBounds(10, 10, 180, 154);
		
		text_1 = new Text(group, SWT.BORDER);
		text_1.setBounds(56, 47, 31, 21);
		
		Label lblK = new Label(group, SWT.NONE);
		lblK.setBounds(10, 53, 41, 15);
		lblK.setText("k");
		
		Label label = new Label(group, SWT.NONE);
		label.setBounds(10, 26, 41, 15);
		label.setText("\u0421\u043B\u043E\u0432\u043E");
		
		text = new Text(group, SWT.BORDER);
		text.setBounds(56, 20, 112, 21);
		
		text_2 = new Text(group, SWT.BORDER);
		text_2.setBounds(31, 120, 112, 21);
		
		Button btnNewButton = new Button(group, SWT.NONE);
		btnNewButton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				String str = text.getText();
				int k = Integer.parseInt(text_1.getText());

				char[] buf = new char[k];
				str.getChars(0, k, buf, 0);			

				String strBuf=str.substring(k);
				str=strBuf;
				strBuf = String.valueOf(buf);
				str += strBuf;
				text_2.setText(str);

			}
		});
		btnNewButton.setBounds(10, 79, 158, 25);
		btnNewButton.setText("\u041F\u0435\u0440\u0435\u043D\u0435\u0441\u0442\u0438");
		
		Group group_1 = new Group(shell, SWT.NONE);
		group_1.setText("\u0427\u0430\u0441\u0442\u0438\u043D\u0430 2");
		group_1.setBounds(196, 10, 228, 154);
		
		text_3 = new Text(group_1, SWT.BORDER);
		text_3.setBounds(10, 23, 76, 21);
		
		text_4 = new Text(group_1, SWT.BORDER);
		text_4.setBounds(10, 50, 76, 21);
		
		text_5 = new Text(group_1, SWT.BORDER);
		text_5.setBounds(10, 77, 76, 21);
		
		final Label lbl1 = new Label(group_1, SWT.NONE);
		lbl1.setBounds(92, 29, 126, 15);
		
		final Label lbl2 = new Label(group_1, SWT.NONE);
		lbl2.setBounds(92, 56, 126, 15);
				
		final Label lbl3 = new Label(group_1, SWT.NONE);
		lbl3.setBounds(92, 83, 126, 15);
		
		Button btnNewButton_1 = new Button(group_1, SWT.NONE);
		btnNewButton_1.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				String s1 = text_3.getText(),
						s2 = text_4.getText(),
						s3 = text_5.getText(),
						s4 = "",
						result = "";
				s4 = s2.concat(s3);
				for (int i = 0; i < s1.length(); i++) {
					if (!s4.contains(s1.substring(i, i+1))) {
//						if (!result.contains(s1.substring(i, i+1))) {
							result += s1.substring(i,i+1);
//						}
					}
				}
				lbl1.setText(result);
				lbl1.setText(result);
				result = "";
				s4 = s1.concat(s3);
				for (int i = 0; i < s2.length(); i++) {
					if (!s4.contains(s2.substring(i, i+1))) {
//						if (!result.contains(s2.substring(i, i+1))) {
							result += s2.substring(i,i+1);
//						}
					}
				}
				lbl2.setText(result);
				result = "";
				s4 = s1.concat(s2);
				for (int i = 0; i < s3.length(); i++) {
					if (!s4.contains(s3.substring(i, i+1))) {
//						if (!result.contains(s3.substring(i, i+1))) {
							result += s3.substring(i,i+1);
//						}
					}
				}
				lbl3.setText(result);
				result = "";
			}
		});
		btnNewButton_1.setBounds(10, 114, 75, 25);
		btnNewButton_1.setText("without");
		
		Button btnNewButton_2 = new Button(group_1, SWT.NONE);
		btnNewButton_2.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				String s1 = text_3.getText(),
						s2 = text_4.getText(),
						s3 = text_5.getText(),
						s4 = "",
						result = "";
				s4 = s2.concat(s3);
				for (int i = 0; i < s1.length(); i++) {
					if (!s4.contains(s1.substring(i, i+1))) {
						if (!result.contains(s1.substring(i, i+1))) {
							result += s1.substring(i,i+1);
						}
					}
				}
				lbl1.setText(result);
				result = "";
				s4 = s1.concat(s3);
				for (int i = 0; i < s2.length(); i++) {
					if (!s4.contains(s2.substring(i, i+1))) {
						if (!result.contains(s2.substring(i, i+1))) {
							result += s2.substring(i,i+1);
						}
					}
				}
				lbl2.setText(result);
				result = "";
				s4 = s1.concat(s2);
				for (int i = 0; i < s3.length(); i++) {
					if (!s4.contains(s3.substring(i, i+1))) {
						if (!result.contains(s3.substring(i, i+1))) {
							result += s3.substring(i,i+1);
						}
					}
				}
				lbl3.setText(result);
				result = "";
			}
		});
		btnNewButton_2.setBounds(102, 114, 75, 25);
		btnNewButton_2.setText("with");
		
		
		

		shell.open();
		shell.layout();
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch()) {
				display.sleep();
			}
		}
	}
}
