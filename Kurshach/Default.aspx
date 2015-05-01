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
    
        <asp:CheckBox ID="CheckBox1" runat="server" AutoPostBack="True" OnCheckedChanged="CheckBox_CheckedChanged" Text="" />
        <asp:CheckBox ID="CheckBox2" runat="server" AutoPostBack="True" OnCheckedChanged="CheckBox_CheckedChanged" Text="" />
        <asp:CheckBox ID="CheckBox3" runat="server" AutoPostBack="True" OnCheckedChanged="CheckBox_CheckedChanged" Text="" />
        <asp:CheckBox ID="CheckBox4" runat="server" AutoPostBack="True" OnCheckedChanged="CheckBox_CheckedChanged" Text="" />
        <asp:CheckBox ID="CheckBox5" runat="server" AutoPostBack="True" OnCheckedChanged="CheckBox_CheckedChanged" Text="" />
        <asp:CheckBox ID="CheckBox6" runat="server" AutoPostBack="True" OnCheckedChanged="CheckBox_CheckedChanged" />
        <asp:CheckBox ID="CheckBox7" runat="server" />
        <asp:CheckBox ID="CheckBox8" runat="server" />
        <asp:CheckBox ID="CheckBox9" runat="server" />
        <asp:CheckBox ID="CheckBox10" runat="server" />
        <asp:CheckBox ID="CheckBox11" runat="server" />
        <asp:CheckBox ID="CheckBox12" runat="server" />
        <asp:CheckBox ID="CheckBox13" runat="server" />
        <asp:CheckBox ID="CheckBox14" runat="server" />
        <asp:CheckBox ID="CheckBox15" runat="server" />
        <asp:CheckBox ID="CheckBox16" runat="server" />
        <asp:CheckBox ID="CheckBox17" runat="server" />
        <asp:CheckBox ID="CheckBox18" runat="server" />
        <asp:CheckBox ID="CheckBox19" runat="server" />
        <asp:CheckBox ID="CheckBox20" runat="server" />
        <br />
    
        <asp:Image ID="Image1" runat="server" Height="305px" Width="487px" ImageUrl="App_Data/Map_of_Ukraine_political_simple_city_Kiew.png"/>
        <asp:ListBox ID="ListBox1" runat="server" DataSourceID="Database" DataTextField="Name" DataValueField="Id" Height="288px" SelectionMode="Multiple" style="margin-top: 0px"></asp:ListBox>
        <asp:ListBox ID="ListBox2" runat="server" Width="200px"></asp:ListBox>
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Link" />
        <asp:Button ID="Button2" runat="server" Text="Prima" OnClick="Button2_Click" />
        <asp:Label ID="Label1" runat="server" Text="Відстань:"></asp:Label>
        <asp:Label ID="Label2" runat="server"></asp:Label>
        <asp:Button ID="Button3" runat="server" Text="Button" />
        <asp:SqlDataSource ID="Database" runat="server" ConnectionString="<%$ ConnectionStrings:BigDatabase %>" SelectCommand="SELECT [Id], [Name] FROM [City]"></asp:SqlDataSource>
    
    </div>
    </form>
</body>
</html>
