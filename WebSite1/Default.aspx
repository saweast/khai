<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div style="float: left;">
    <asp:Panel ID="Panel1" runat="server" Height="173px" Width="210px">
            <asp:Label ID="Label4" runat="server" Text="Назва"></asp:Label>
            <asp:TextBox ID="tbName" runat="server" Width="120px"></asp:TextBox>
            <br />
            <asp:TextBox ID="tbX" runat="server" Width="60px"></asp:TextBox>
            <asp:TextBox ID="tbY" runat="server" Width="60px"></asp:TextBox>
            <br />
            <asp:Button ID="Button3" runat="server" OnClick="Button3_Click" Text="Додати" />
            <br />
            <br />
            <asp:DropDownList ID="ddEname" runat="server" DataSourceID="SqlDataSourceVertexes" DataTextField="name" DataValueField="Id" OnSelectedIndexChanged="DropDownList1_SelectedIndexChanged" AutoPostBack="True">
            </asp:DropDownList>
            <asp:TextBox ID="tbEname" runat="server" AutoCompleteType="Enabled"></asp:TextBox>
            <br />
            <asp:TextBox ID="tbEx" runat="server" Width="60px"></asp:TextBox>
            <asp:TextBox ID="tbEy" runat="server" Width="60px"></asp:TextBox>
            <br />
            <asp:Button ID="Button4" runat="server" OnClick="Button4_Click" Text="Редагувати" />
        </asp:Panel>
    
        <asp:Label ID="Label1" runat="server" Text="Звідки"></asp:Label>
        <asp:DropDownList ID="ddlFrom" runat="server" DataSourceID="SqlDataSourceVertexes" DataTextField="name" DataValueField="Id" AutoPostBack="True" OnSelectedIndexChanged="ddlFrom_SelectedIndexChanged">
        </asp:DropDownList>
        <br />
        <asp:Label ID="Label2" runat="server" Text="Куди"></asp:Label>
        <asp:DropDownList ID="ddTo" runat="server" DataSourceID="SqlDataSourceVertexes" DataTextField="name" DataValueField="Id" AutoPostBack="True" OnSelectedIndexChanged="ddTo_SelectedIndexChanged">
        </asp:DropDownList>
        <br />
        <asp:Label ID="Label3" runat="server" Text="Відстань"></asp:Label>
        <asp:TextBox ID="weight" runat="server"></asp:TextBox>
        <br />
        <asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="Додати" />
        <br />
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:DatabaseConnectionString %>" SelectCommand="SELECT * FROM [Edges]"></asp:SqlDataSource>
        <asp:ListBox ID="ListBox4" runat="server" Width="254px"></asp:ListBox>
        <asp:SqlDataSource ID="SqlDataSourceVertexes" runat="server" ConnectionString="<%$ ConnectionStrings:DatabaseConnectionString %>" SelectCommand="SELECT * FROM [Vertexes]"></asp:SqlDataSource>
        <br /><asp:ListBox ID="ListBox5" runat="server" Width="247px"></asp:ListBox>
        <br />
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Рахувати" />
    
    </div>
    <iframe src="http://127.0.0.1/" height="550" style="float: right; width:70%"></iframe>
    </form>
    </body>
</html>
