// InvestLab. Структурная GUI-модель в SysML v2 textual notation.
// PNG-эскизы экрана являются иллюстрациями нижеописанной структуры.
package InvestLabGUI {
    part def InputField;
    part def Selector;
    part def ActionButton;
    part def FinancialChart;
    part def ResultsTable;
    part def MetricCard;
    part def NoticeArea;

    part def PortfolioSetupScreen {
        part assetSelector : Selector;
        part dateFrom : InputField;
        part dateTo : InputField;
        part initialAmount : InputField;
        part allocationMode : Selector;
        part assetWeights : ResultsTable;
        part strategySelector : Selector;
        part strategySettings : InputField;
        part feePercent : InputField;
        part runSimulation : ActionButton;
        part validationMessages : NoticeArea;
    }
    part def SimulationResultsScreen {
        part returnSummary : MetricCard;
        part endCapitalSummary : MetricCard;
        part maximumDrawdownSummary : MetricCard;
        part capitalOverTime : FinancialChart;
        part operationsSummary : ResultsTable;
        part saveResult : ActionButton;
        part calculationNotice : NoticeArea;
    }
    part def HistoryScreen {
        part savedRuns : ResultsTable;
        part openSavedRun : ActionButton;
    }
    part def InvestLabDesktop {
        part setup : PortfolioSetupScreen;
        part result : SimulationResultsScreen;
        part history : HistoryScreen;
    }
    part application : InvestLabDesktop;
}
