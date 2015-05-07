<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Calculator.aspx.cs" Inherits="Lab10.Calculator" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
    <head runat="server">
        <meta charset="utf-8" />
        <title>Calculator</title>
        <link href="../css/StyleCalculator.css" type="text/css" rel="stylesheet" />
    </head>
    <body>
        <h1>Calculator v1.0</h1>
        <form id="formCalculator" runat="server">
            <div id="Expression">
                <asp:TextBox runat="server" ID="Operand1"></asp:TextBox>
                <asp:Label runat="server" ID="Operation">+</asp:Label>
                <asp:TextBox runat="server" ID="Operand2"></asp:TextBox>
            </div>
            <div id="Operations">
                <asp:Button class="inputOperations" runat="server" ID="Plus" Text="+" OnClick="Plus_Click" />
                <asp:Button class="inputOperations" runat="server" ID="Minus" Text="-" OnClick="Minus_Click" />
                <asp:Button class="inputOperations" runat="server" ID="Multiply"  Text="*" OnClick="Multiply_Click" />
                <asp:Button class="inputOperations" runat="server" ID="Devision"  Text="/" OnClick="Devision_Click" />
            </div>
            <div id="Results">
                <asp:Button Text="Result" runat="server" ID="Calculate" OnClick="Calculate_Click" />
                <asp:Label runat="server" ID="Result" >= </asp:Label>
            </div>
        </form>
    </body>
</html>
