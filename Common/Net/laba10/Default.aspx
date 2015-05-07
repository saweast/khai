<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <asp:Label ID="Label1" runat="server"></asp:Label>
        <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
        <asp:Label ID="Label2" runat="server" Text=" = "></asp:Label>
        <asp:Label ID="Label3" runat="server"></asp:Label>
        <br />
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="+" />
        <asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="-" />
        <asp:Button ID="Button3" runat="server" OnClick="Button3_Click" Text="*" />
        <asp:Button ID="Button4" runat="server" OnClick="Button4_Click" Text="/" />
        <br />
        <asp:DataGrid ID="DataGridStudents" runat="server" AutoGenerateColumns="False" OnSelectedIndexChanged="dgStudents_SelectedIndexChanged">
            <Columns>
                <asp:BoundColumn DataField="Id" HeaderText="Id"></asp:BoundColumn>
                <asp:BoundColumn DataField="FirstName" HeaderText="First Name"></asp:BoundColumn>
                <asp:BoundColumn DataField="LastName" HeaderText="Last Name"></asp:BoundColumn>
                <asp:BoundColumn DataField="Date" DataFormatString="{0:d}" HeaderText="Birth Day"></asp:BoundColumn>
            </Columns>
        </asp:DataGrid>
    
    </div>
    </form>
</body>
</html>
