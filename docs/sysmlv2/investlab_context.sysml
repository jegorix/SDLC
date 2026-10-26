// InvestLab. Контекстная структура модели (SysML v2 textual notation).
// Логическая модель компонентов, не код приложения.
package InvestLabContext {
    part def Investor;
    part def MarketDataAPI;
    part def SQLiteStorage;
    part def FinancialSimulation;
    part def PortfolioManagement;
    part def UserInterface;
    part def InvestLab {
        part gui : UserInterface;
        part portfolio : PortfolioManagement;
        part simulation : FinancialSimulation;
        part persistence : SQLiteStorage;
        part quotes : MarketDataAPI;
    }
    part user : Investor;
    part desktopApp : InvestLab;
}
