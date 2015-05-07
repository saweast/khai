<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Students.aspx.cs" Inherits="Lab10.pages.Students" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
    <head runat="server">
        <meta charset="utf-8" />
        <title>Students</title>
        <link href="../css/StyleStudents.css" type="text/css" rel="stylesheet" />
    </head>
    <body>
        <asp:Label runat="server" ID="ErrorMessage"></asp:Label>
        <h1>Students</h1>
        <asp:DataGrid runat="server" ID="dgStudents" AutoGenerateColumns="false" OnSelectedIndexChanged="dgStudents_SelectedIndexChanged">
            <Columns>
                <asp:BoundColumn HeaderText="StudentID" DataField="StudentID"></asp:BoundColumn>
                <asp:BoundColumn HeaderText="FirstName" DataField="FirstName"></asp:BoundColumn>
                <asp:BoundColumn HeaderText="LastName" DataField="LastName"></asp:BoundColumn>
                <asp:BoundColumn HeaderText="BirthDate" DataField="BirthDate" DataFormatString="{0:d}"></asp:BoundColumn>
            </Columns>
        </asp:DataGrid>
    </body>
</html>
